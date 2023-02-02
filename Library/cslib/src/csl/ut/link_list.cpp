#include "csl/ut/link_list.h"

namespace csl
{
namespace ut
{
namespace detail
{
void LinkListImpl::Initialize()
{
    m_count = 0;
    m_root.Next = &m_root;
    m_root.Prev = &m_root;
}

LinkListImpl::iterator LinkListImpl::insert(iterator it, LinkListNode* node)
{
    ++m_count;

    LinkListNode* prev = it.Node->Prev;
    node->Next = it.Node;
    node->Prev = prev;

    it.Node->Prev = node;
    prev->Next = node;

    return iterator(node, m_nodeOffset);
}

LinkListImpl::iterator LinkListImpl::erase(LinkListNode* node)
{
    LinkListNode* next = node->Next;
    node->Next->Prev = node->Prev;
    node->Prev->Next = next;

    node->Next = nullptr;
    node->Prev = nullptr;
    --m_count;

    return iterator(next, m_nodeOffset);
}

LinkListImpl::iterator LinkListImpl::erase(iterator first, iterator last)
{
    for (LinkListNode* curNode = first.Node;
        curNode != last.Node;
        curNode = curNode->Next)
    {
        erase(curNode);
    }

    return last;
}

LinkListImpl::iterator LinkListImpl::erase(iterator it)
{
    return erase(it, iterator(it.Node->Next, it.NodeOffset));
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
}
}
}
