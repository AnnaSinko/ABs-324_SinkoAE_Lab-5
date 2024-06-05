package main

import (
	"fmt"
	"math/rand"
	"time"
)

type visitor struct {
	ticket string
}

func main() {
	var number int
	fmt.Println("Введите кол-во окон")
	fmt.Scan(&number)

	windows := make([]chan visitor, number)
	for i := range windows {
		windows[i] = make(chan visitor, 100)
	}

	Time := make([]int, number)

	rand.Seed(time.Now().UnixNano())

	for {
		var command string
		fmt.Println("Введите команду (ENQUEUE/DISTRIBUTE) и время: ")
		fmt.Scan(&command)

		if command == "ENQUEUE" {
			var time int
			fmt.Scan(&time)

			person := visitor{ticket: fmt.Sprintf("T%d", rand.Intn(1000))}

			minKol := 0
			for i := 1; i < number; i++ {
				if Time[i] < Time[minKol] {
					minKol = i
				}
			}

			windows[minKol] <- person
			Time[minKol] += time
			fmt.Println("Ваш талон: ", person.ticket)
		} else if command == "DISTRIBUTE" {
			for i := 0; i < number; i++ {
				fmt.Printf("Окно %d (%d минут): ", i+1, Time[i])
				for len(windows[i]) > 0 {
					person := <-windows[i]
					fmt.Print(person.ticket)
					if len(windows[i]) > 0 {
						fmt.Print(", ")
					}
				}
				fmt.Println()
			}
			break
		}
	}
}