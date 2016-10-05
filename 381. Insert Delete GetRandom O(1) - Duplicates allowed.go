package main

import (
	"time"
	"math/rand"
	"fmt"
)

type indexlist struct {
	ar []int//index1,index2,index3
}
type RandomizedCollection struct {
	mp map[int]*indexlist
	ar []int
	tail int
}

func Constructor() RandomizedCollection {
	rand.Seed(int64(time.Now().Nanosecond()))
	mp := RandomizedCollection{}
	mp.mp = make(map[int]*indexlist)
	mp.ar = make([]int,1)
	mp.tail = 0
	return mp
}
func (this *RandomizedCollection) Disply(){
	return
	fmt.Println("len",this.tail+1)
	for i,v:= range this.ar{
		fmt.Println(i,":",v)
	}
	fmt.Println("xxxxxxxxx")
}
func (this *RandomizedCollection) Insert(val int) bool {

	 v, ok := this.mp[val]
	rf :=false
	if !ok{
		v = &indexlist{}
		v.ar = make([]int,0)
		this.mp[val] = v
		rf =true
	}
	if( this.tail + 1 == len(this.ar)){
		this.ar = append(this.ar,0)
	}
	this.ar[this.tail] = val
	v.ar = append(v.ar,this.tail)
	this.tail++
	this.Disply()
	return rf;
}

func (this *RandomizedCollection) Remove(val int) bool {
	if ind, ok := this.mp[val]; ok {
		npos:=ind.ar[len(ind.ar)-1]
		ind.ar = ind.ar[0:len(ind.ar)-1]
		this.ar[npos] = this.ar[this.tail-1]
		for i:=0;i< len(this.mp[this.ar[npos]].ar);i++{
			if this.mp[this.ar[npos]].ar[i] == this.tail-1{
				this.mp[this.ar[npos]].ar[i]=npos
				break;
			}
		}
		this.ar[this.tail-1] = 0
		this.tail--
		if len(ind.ar)==0 {
			delete(this.mp,val)
		}
		this.Disply()
		return true;
	}
	return false;
}

func (this *RandomizedCollection) GetRandom() int {
	return this.ar[rand.Int() % this.tail]
}

func main() {
	mp := Constructor()

	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Remove(1))
	fmt.Println(mp.Remove(1))
	fmt.Println(mp.Remove(1))
	fmt.Println(mp.Remove(1))
	fmt.Println(mp.Remove(1))
	fmt.Println(mp.Insert(2))
	fmt.Println(mp.Insert(1))
	fmt.Println(mp.Remove(2))
	fmt.Println(mp.Remove(2))
	fmt.Println(mp.GetRandom())



}
