#include "pch.h"
#include "csl/ut/linklist.h"

namespace csl
{
namespace ut
{
namespace detail
{
LinkListImpl::iterator LinkListImpl::insert(iterator it, LinkListNode* node)
{
    ++m_count;

    LinkListNode* prev = it.node->prev;
    node->next = it.node;
    node->prev = prev;

    it.node->prev = node;
    prev->next = node;

    return iterator(node, m_nodeOffset);
}

LinkListImpl::iterator LinkListImpl::erase(LinkListNode* node)
{
    LinkListNode* next = node->next;
    node->next->prev = node->prev;
    node->prev->next = next;

    node->next = nullptr;
    node->prev = nullptr;
    --m_count;

    return iterator(next, m_nodeOffset);
}

LinkListImpl::iterator LinkListImpl::erase(iterator first, iterator last)
{
    for (LinkListNode* curNode = first.node;
        curNode != last.node;
        curNode = curNode->next)
    {
        erase(curNode);
    }

    return last;
}

LinkListImpl::iterator LinkListImpl::erase(iterator it)
{
    return erase(it, iterator(it.node->next, it.nodeOffset));
}

void LinkListImpl::init(int nodeOffset)
{
    m_nodeOffset = nodeOffset;
}

void LinkListImpl::clear()
{
    erase(begin(), end());
}

void LinkListImpl::reverse()
{
    if (m_count != 0)
    {
        LinkListNode* curNode = m_root.next;
        m_root.prev = &m_root;
        m_root.next = &m_root;

        m_count = 0;
        while (curNode != &m_root)
        {
            LinkListNode* next = curNode->next;
            curNode->prev = nullptr;
            curNode->next = nullptr;

            insert(iterator(m_root.next, m_nodeOffset), curNode);

            curNode = next;
        }
    }
}
} // detail
} // ut
} // csl
