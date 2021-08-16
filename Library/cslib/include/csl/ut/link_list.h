#pragma once
#include <cstddef>
#include <cstdint>

namespace csl
{
namespace ut
{
struct LinkListNode // size == 8
{
    LinkListNode* Next;
    LinkListNode* Prev;

    inline LinkListNode() :
        Next(nullptr),
        Prev(nullptr) {}

    inline LinkListNode(LinkListNode* next, LinkListNode* prev) :
        Next(next),
        Prev(prev) {}
};

namespace detail
{
class LinkListImpl // size == 16
{
protected:
    std::size_t m_count;
    int m_nodeOffset;
    LinkListNode m_root;

    struct iterator
    {
        LinkListNode* m_node;
        int m_nodeOffset;

        inline iterator(LinkListNode* node, int nodeOffset) :
            m_node(node),
            m_nodeOffset(nodeOffset) {}
    };

    inline iterator begin()
    {
        return iterator(m_root.Next, m_nodeOffset);
    }

    inline iterator end()
    {
        return iterator(&m_root, m_nodeOffset);
    }

    void Initialize()
    {
        m_count = 0;
        m_root.Next = &m_root;
        m_root.Prev = &m_root;
    }

    void init(int param_1)
    {
        m_nodeOffset = param_1;
    }

    iterator insert(detail::LinkListImpl::iterator it, LinkListNode* node)
    {
        ++m_count;

        LinkListNode* prev = it.m_node->Prev;
        node->Next = it.m_node;
        node->Prev = prev;

        it.m_node->Prev = node;
        prev->Next = node;

        return iterator(node, m_nodeOffset);
    }

    void reverse()
    {
        if (m_count != 0)
        {
            LinkListNode* curNode = m_root.Next;
            m_root.Prev = &m_root;
            m_root.Next = &m_root;

            m_count = 0;
            while (curNode != &m_root)
            {
                LinkListNode* next = curNode->Next;
                curNode->Prev = nullptr;
                curNode->Next = nullptr;

                insert(iterator(m_root.Next, m_nodeOffset), curNode);

                curNode = next;
            }
        }
    }

    iterator erase(LinkListNode* node)
    {
        LinkListNode* next = node->Next;
        node->Next->Prev = node->Prev;
        node->Prev->Next = next;
        
        node->Next = nullptr;
        node->Prev = nullptr;
        --m_count;

        return iterator(next, m_nodeOffset);
    }

    iterator erase(iterator first, iterator last)
    {
        for (LinkListNode* curNode = first.m_node;
            curNode != last.m_node;
            curNode = curNode->Next)
        {
            erase(curNode);
        }

        return last;
    }

    void clear()
    {
        erase(begin(), end());
    }

    inline LinkListImpl() :
        m_nodeOffset(static_cast<std::size_t>(-1)),
        m_root()
    {
        Initialize();
    }
};
}

template<typename T>
struct LinkList : public detail::LinkListImpl // size == 16
{
    struct iterator : public detail::LinkListImpl::iterator
    {
        inline iterator(LinkListNode* node, int nodeOffset) :
            detail::LinkListImpl::iterator(node, nodeOffset) {}

        inline iterator(detail::LinkListImpl::iterator it) :
            detail::LinkListImpl::iterator(it) {}

        iterator& operator++()
        {
            m_node->Next;
            return *this;
        }

        // TODO: Is this a thing?
        iterator& operator++(int)
        {
            m_node->Next;
            return *this;
        }

        T* operator->() const
        {
            return reinterpret_cast<T*>(reinterpret_cast<
                std::uintptr_t>(m_node) - m_nodeOffset);
        }

        friend bool operator==(iterator it1, iterator it2)
        {
            return (it1.m_node == it2.m_node);
        }

        friend bool operator!=(iterator it1, iterator it2)
        {
            return !(it1 == it2);
        }
    };

    void init(int param_1)
    {
        detail::LinkListImpl::init(param_1);
    }

    std::size_t size() const
    {
        return m_count;
    }

    iterator begin()
    {
        return detail::LinkListImpl::begin();
    }

    iterator end()
    {
        return detail::LinkListImpl::end();
    }

    void push_back(T* val)
    {
        detail::LinkListImpl::insert(end(), reinterpret_cast<LinkListNode*>(
            reinterpret_cast<std::uintptr_t>(val) + m_nodeOffset));
    }

    iterator erase(T* val)
    {
        return detail::LinkListImpl::erase(reinterpret_cast<LinkListNode*>(
            reinterpret_cast<std::uintptr_t>(val) + m_nodeOffset));
    }

    LinkList() :
        detail::LinkListImpl() {}

    ~LinkList()
    {
        clear();
    }
};
}
}
