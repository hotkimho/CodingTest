package main

import (
	"fmt"
	"sort"
)

var n int
var lost []int
var reserve []int

func solution() int {
	result := n

	save := make([]int, n+2)

	for _, v := range reserve {
		save[v] = 1
	}

	for i, v := range lost {
		if save[v] == 1 {
			save[v] = 0
			lost[i] = -1
		}
	}
	sort.Ints(lost)
	for _, v := range lost {
		if v == -1 {
			continue
		}
		if save[v-1] == 1 {
			save[v-1] = 0
		} else if save[v+1] == 1 {
			save[v+1] = 0
		} else {
			result--
		}
	}
	return result
}
func main() {

	n = 3
	lost = append(lost, 1, 2)
	reserve = append(reserve, 2, 3)
	fmt.Println(solution())
}
