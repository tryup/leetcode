#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


/*
 * 最简单的堆操作,不足，存在不必要的元素交换,可以优化。
 * todo:模板化,比较op适配
 * */
class lyheap
{
    constexpr static int size = 10*2+1;
    int m_heap[size];
    int nowsize = 0;
public:
    bool cmp(int a,int b)
    {
        return a>b;
    }
    void put(int n )
    {
        m_heap[++nowsize] = n;
    }


    /*上滤*/
    void up(int index)
    {
        while( index>=1 )
        {

            if( cmp(m_heap[index],m_heap[index/2]) )
            {
                swap(m_heap[index],m_heap[index/2]);
            }
            else
            {
                break;
            }
            index/=2;
            if( index == 1)
                break;
        }
    }
    /*
     对第index个元素进行下滤*/
    void down(int index)
    {
        bool ok = false;
        int i = 0;

        while( index <=nowsize )
        {

            auto lh = index * 2;
            auto rh = index * 2 + 1;//选取符合条件的字节点需要判断字节点是否为空。
            auto fitnode = lh;
            if( lh > nowsize )
                return;
            if( lh != nowsize && cmp(m_heap[rh],m_heap[ lh ]))//两个字节点,选择符合条件的(最小堆，那么选择下面最小的)
            {
                fitnode = rh;//这个时候fitnode是rh,rh比较小
            }
            //进行下滤。
            if( cmp(m_heap[index],m_heap[fitnode ]))//已经找到位置不需要再变,比下面最小的还小，位置找到。
            {
                return;
            }else
            {
                swap(m_heap[index],m_heap[fitnode]);
                //m_heap[index] = m_heap[fitnode];//不然就交换一下，继续下滤
            }
            index = fitnode;
        }
    }

    void buildheap()
    {
        for( int i = nowsize/2;i>=1 ;--i) //为什么是nowsize/2开始，因为这个永远指向最后一个节点的父节点[最后一排的叶子梅雨哦子叶，不需要下滤]
        {
            down(i);
            disp();
        }
    }

    /*堆排序,最小堆，从小到达排*/
    void sort()
    {
        int os = nowsize;
        while ( nowsize )
        {
            swap( m_heap[1],m_heap[nowsize--]);//放到最后,那么顺序是最大的再最前面
            //下滤，找到位置
            down(1);
        }
        nowsize =os;
    }

    void disp()
    {
        for(int i = 1; i <=nowsize; ++i)
        {
            cout << m_heap[ i ] << " ";
        }
        cout << endl;
    }
};


int main()
{
    lyheap heap;
   //vector<int> v = { 10,2,7,4,5,6,8};
    //vector<int> v = { 3,4,5,6,1,7,8};
    vector<int> v = { 9,8,7,7,6,5,4,3,2,1};
    for(auto i :v){
        heap.put(i);
    }
    std::greater<int>();

    heap.disp();
/*
    for (int j = 0; j < v.size(); ++j) {
        heap.down(j+1);
        heap.disp();
    }
*/
    heap.buildheap();
    //heap.up(5);
    heap.disp();
    heap.sort();
    heap.disp();


    return 0;
}