struct cachenode
{
    cachenode(int _key,int _val,std::list<int>::iterator it):key(_key),val(_val),ttlind(it) {

    }

    bool operator <(const cachenode& lhs) const
    {
        return lhs.key<key;
    }
    bool operator ==(const cachenode& lhs) const
    {
        return lhs.key == key;
    }
    int key;
    int val;
    std::list<int>::iterator ttlind;
};


namespace std
{
    template<>
    struct hash<cachenode>
    {
        size_t  operator()(const cachenode& _x) const
        {
            return _x.key;
        }
    };
}


class LRUCache{

    typedef std::unordered_map<int,cachenode> hashtable_t;
    typedef std::list<int> ttllist_t;
public:
    LRUCache(int capacity) {
        m_maxcap = capacity;
    }

    int get(int key) {

        auto iter = _get(key);
        if( iter!= std::end(m_cachelist) )
        {
            _updatetimetick(iter->second,false);
            return  iter->second.val;
        }
        return -1;
    }

    void set(int key, int value) {

        hashtable_t::iterator iter = _get(key);

        if( iter!= std::end(m_cachelist) )
        {
            iter->second.val = value;
            _updatetimetick(iter->second,false);
        }
        else
        {
            if( m_cachelist.size() == m_maxcap )
            {
                m_cachelist.erase(m_ttllist.front());
                m_ttllist.erase(m_ttllist.begin());
            }
            cachenode _t(key,value,m_ttllist.insert(m_ttllist.end(),key));
            m_cachelist.insert( {key,_t});
        }
    }


private:
    hashtable_t::iterator _get(int key)
    {
        return m_cachelist.find( key );
    }


    void _updatetimetick(cachenode& c,bool f)
    {
        m_ttllist.erase(c.ttlind);
        c.ttlind = m_ttllist.insert( m_ttllist.end(), c.key);
    }
    int m_maxcap;
    hashtable_t m_cachelist;
    ttllist_t m_ttllist;
};
