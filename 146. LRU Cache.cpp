struct cachenode
{
    cachenode(int _key,int _val,int _t):key(_key),val(_val),t(_t) {

    }
    int key;
    int val;
    int t;
};

class LRUCache{
public:
    LRUCache(int capacity) {
        m_maxcap = capacity;
    }

    int get(int key) {
        m_time++;
        auto iter = _get(key);
        if( iter!= std::end(m_cachelist) )
        {
            (*iter).t = m_time;
            return (*iter).val;
        }
        return -1;
    }

    void set(int key, int value) {

        m_time++;
        auto iter = _get(key);
        if( iter!= std::end(m_cachelist) )
        {
            (*iter).val = value;
            (*iter).t = m_time;
        }
        else
        {
            if( m_cachelist.size() < m_maxcap )
            {
                m_cachelist.push_back( cachenode(key,value,m_time) );
            }
            else
            {
                //update cache
                int ind = -1;
                int min = -1;
                for(int i = 0 ; i <  m_cachelist.size() ;++i )
                {
                    if( m_cachelist[i].t < min || min == -1)
                    {
                        min = m_cachelist[i].t;
                        ind = i;
                    }
                }
                m_cachelist[ind].key = key;
                m_cachelist[ind].val = value;
                m_cachelist[ind].t = m_time;
            }
        }
    }



private:
    std::vector<cachenode>::iterator _get(int key)
    {
        return std::find_if(std::begin(m_cachelist),
                                 std::end(m_cachelist),
                                 [&](const cachenode& n)->bool{ return n.key == key;}
        );

    }
    int m_maxcap;
    int m_time = 0;
    std::vector<cachenode> m_cachelist;// o(n) linear time
};
