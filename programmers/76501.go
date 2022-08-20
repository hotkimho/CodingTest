package main

import "fmt"

var absolutes []int
var signs []bool

func solution() int {
	result := 0

	for k, v := range absolutes {
		if signs[k] {
			result += v
		} else {
			result -= v
		}
	}
	return result
}

func main() {
	absolutes = append(absolutes, 4)
	absolutes = append(absolutes, 7)
	absolutes = append(absolutes, 12)
	signs = append(signs, true)
	signs = append(signs, false)
	signs = append(signs, true)
	fmt.Println(solution())
}
