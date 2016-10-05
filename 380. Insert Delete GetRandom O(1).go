package main

import (
	"time"
	"math/rand"
	"fmt"
)


type RandomizedSet struct {
	mp map[int]int
	ar []int
	tail int
}

func Constructor() RandomizedSet {
	rand.Seed(int64(time.Now().Nanosecond()))
	mp := RandomizedSet{}
	mp.mp = make(map[int]int)
	mp.ar = make([]int,1)
	mp.tail = 0
	return mp
}
func (this *RandomizedSet) Disply(){
	return
	fmt.Println("len",this.tail+1)
	for i,v:= range this.ar{
		fmt.Println(i,":",v)
	}
	fmt.Println("xxxxxxxxx")
}
func (this *RandomizedSet) Insert(val int) bool {

	if _, ok := this.mp[val]; !ok {
		if( this.tail + 1 == len(this.ar)){
			this.ar = append(this.ar,0)
		}
		this.ar[this.tail] = val
		this.mp[val] = this.tail
		this.tail++
		this.Disply()
		return true;
	}
	return false;
}

func (this *RandomizedSet) Remove(val int) bool {
	if ind, ok := this.mp[val]; ok {
		this.ar[ind] = this.ar[this.tail-1];
		this.mp[this.ar[ind]]=ind
		this.ar[this.tail-1] = 0
		this.tail--
		delete(this.mp, val)
		this.Disply()
		return true;
	}
	return false;
}

func (this *RandomizedSet) GetRandom() int {
	return this.ar[rand.Int() % this.tail]
}

func main() {
	mp := Constructor()
	fmt.Println(mp.Insert(0))
	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Remove(0))
	fmt.Println(mp.Insert(2))
	fmt.Println(mp.Remove(1))
	fmt.Println(mp.GetRandom())

}

