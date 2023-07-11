// TODO: Both the name of this file and its path were guessed!
#pragma once
#include <cstddef>

namespace csl
{
namespace ut
{
namespace detail
{
// TODO: Is this struct really a thing?
struct input_iterator_tag {};

// TODO: Is this struct really a thing?
struct output_iterator_tag {};

// TODO: Is this struct really a thing?
struct forward_iterator_tag : public input_iterator_tag {};

// TODO: Is this struct really a thing?
struct bidirectional_iterator_tag : public forward_iterator_tag {};

// TODO: Is this struct really a thing?
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef typename Category                   iterator_category;
    typedef typename T                          value_type;
    typedef typename Distance                   difference_type;
    typedef typename Pointer                    pointer;
    typedef typename Reference                  reference;
};

template<class Iter>
struct iterator_traits
{
    typedef typename Iter::difference_type      difference_type;
    typedef typename Iter::value_type           value_type;
    typedef typename Iter::pointer              pointer;
    typedef typename Iter::reference            reference;
    typedef typename Iter::iterator_category    iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef std::ptrdiff_t                      difference_type;
    typedef T                                   value_type;
    typedef T*                                  pointer;
    typedef T&                                  reference;
    typedef random_access_iterator_tag          iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
    typedef std::ptrdiff_t                      difference_type;
    typedef T                                   value_type;
    typedef const T*                            pointer;
    typedef const T&                            reference;
    typedef random_access_iterator_tag          iterator_category;
};

template<class Iter>
class reverse_iterator
{
OPENLW_PRIVATE
    Iter m_it;

public:
    typedef Iter                                                        iterator_type;
    typedef typename iterator_traits<Iter>::iterator_category           iterator_category;
    typedef typename iterator_traits<Iter>::value_type                  value_type;
    typedef typename iterator_traits<Iter>::difference_type             difference_type;
    typedef typename iterator_traits<Iter>::pointer                     pointer;
    typedef typename iterator_traits<Iter>::reference                   reference;

    inline reverse_iterator(Iter it) :
        m_it(it) {}

    reverse_iterator<Iter>& operator++()
    {
        --m_it;
        return *this;
    }

    typename iterator<iterator_category, value_type, difference_type, pointer, reference>::pointer operator->() const
    {
        auto tmp = m_it;
		return (--tmp).operator->();
    }

    // TODO: Does this function actually exist?
    typename iterator<iterator_category, value_type, difference_type, pointer, reference>::reference operator*() const
    {
        return *operator->();
    }

    friend bool operator==(const reverse_iterator<Iter>& it1, const reverse_iterator<Iter>& it2)
    {
        return (it1.m_it == it2.m_it);
    }

    friend bool operator!=(const reverse_iterator<Iter>& it1, const reverse_iterator<Iter>& it2)
    {
        return !(it1 == it2);
    }
};
} // detail
} // ut
} // csl
