struct cachenode
{
    cachenode(int _key,int _val,int _t):key(_key),val(_val),t(_t) {

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
    int t;
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
public:
    LRUCache(int capacity) {
        m_maxcap = capacity;
    }

    int get(int key) {
        m_time++;
        auto iter = _get(key);
        if( iter!= std::end(m_cachelist) )
        {
            return  iter->second.val;
        }
        return -1;
    }

    void set(int key, int value) {

        m_time++;
        hashtable_t::iterator iter = _get(key);
        if( iter!= std::end(m_cachelist) )
        {
            iter->second.val = value;
        }
        else
        {
            m_cachelist.insert( make_pair(key, cachenode(key,value,0)));
        }
    }



private:
    hashtable_t::iterator _get(int key)
    {
        return m_cachelist.find( key );
    }
    int m_maxcap;
    int m_time = 0;

    hashtable_t m_cachelist;

};