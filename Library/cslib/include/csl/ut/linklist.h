#pragma once
#include <cstddef>
#include <cstdint>

namespace csl
{
namespace ut
{
struct LinkListNode
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

LWAPI_STATIC_ASSERT_SIZE(LinkListNode, 8)

namespace detail
{
class LinkListImpl
{
OPENLW_PROTECTED
    std::size_t m_count;
    int m_nodeOffset;
    LinkListNode m_root;

    struct iterator
    {
        LinkListNode* Node;
        int NodeOffset;

        inline iterator(LinkListNode* node, int nodeOffset) :
            Node(node),
            NodeOffset(nodeOffset) {}
    };

    inline iterator begin()
    {
        return iterator(m_root.Next, m_nodeOffset);
    }

    inline iterator end()
    {
        return iterator(&m_root, m_nodeOffset);
    }

    LWAPI(0x02014CD0, NONE)
    void Initialize()
    {
        m_count = 0;
        m_root.Next = &m_root;
        m_root.Prev = &m_root;
    }

    LWAPI(0x02CA6E98, 0x00962180)
    iterator insert(iterator it, LinkListNode* node);

    LWAPI(0x02CA6ED4, 0x009621b0)
    iterator erase(LinkListNode* node);

    LWAPI(0x02CA6F14, 0x009621e0)
    iterator erase(iterator first, iterator last);

    LWAPI(0x02CA6F64, 0x009622b0)
    iterator erase(iterator it);

    LWAPI(0x02CA6FB8, 0x00962170)
    void init(int nodeOffset);

    LWAPI(0x02CA6FC0, 0x00962280)
    void clear();

    LWAPI(0x02CA7024, 0x00962230)
    void reverse();

    inline LinkListImpl(int nodeOffset = -1) :
        m_nodeOffset(nodeOffset)
    {
        Initialize();
    }
};

LWAPI_STATIC_ASSERT_SIZE(LinkListImpl, 16)
} // detail

template<typename T>
class LinkList : public detail::LinkListImpl
{
public:
    struct iterator : public detail::LinkListImpl::iterator
    {
        inline iterator(LinkListNode* node, int nodeOffset) :
            detail::LinkListImpl::iterator(node, nodeOffset) {}

        inline iterator(detail::LinkListImpl::iterator it) :
            detail::LinkListImpl::iterator(it) {}

        iterator& operator++()
        {
            Node = Node->Next;
            return *this;
        }

        T* operator->() const
        {
            return reinterpret_cast<T*>(reinterpret_cast<
                std::uintptr_t>(Node) - NodeOffset);
        }

        T& operator*() const
        {
            return *operator->();
        }

        friend bool operator==(iterator it1, iterator it2)
        {
            return (it1.Node == it2.Node);
        }

        friend bool operator!=(iterator it1, iterator it2)
        {
            return !(it1 == it2);
        }
    };

    void init(int nodeOffset)
    {
        detail::LinkListImpl::init(nodeOffset);
    }

    bool empty() const
    {
        return (m_count == 0);
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

    iterator erase(iterator it)
    {
        return detail::LinkListImpl::erase(it);
    }

    void clear()
    {
        detail::LinkListImpl::clear();
    }

    LinkList() :
        detail::LinkListImpl() {}

    LinkList(int nodeOffset) :
        detail::LinkListImpl(nodeOffset) {}

    ~LinkList()
    {
        clear();
    }
};
} // ut
} // csl
