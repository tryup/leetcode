package main

import (
	"time"
	"math/rand"
	"fmt"
)

type RandomizedSet struct {
	mp map[int]int
}

func Constructor() RandomizedSet {
	rand.Seed(int64(time.Now().Nanosecond()))
	mp := RandomizedSet{}
	mp.mp = make(map[int]int)
	return mp
}

func (this *RandomizedSet) Insert(val int) bool {

	if _, ok := this.mp[val]; !ok {
		this.mp[val] = 1;
		return true;
	}
	return false;
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.mp[val]; ok {
		delete(this.mp, val)
		return true;
	}
	return false;
}

func (this *RandomizedSet) GetRandom() int {
	i := rand.Int() % len(this.mp)
	s, v := 0, 0
	for k, _ := range this.mp {
		if s == i {
			v = k
			break
		}
		s++
	}
	return v
}

func main() {
	mp := Constructor()
	fmt.Println(mp)
	fmt.Println(mp.Insert(10))
	fmt.Println(mp.Insert(12))
	fmt.Println(mp.GetRandom())

}
