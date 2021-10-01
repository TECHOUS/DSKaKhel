package main

import ( 
	"fmt"
	"strings"
)

func main() {

	// string concatenation
	s1 := "a black car"
	fmt.Println(s1)

    s2 := s1 + " and a bycle"
	fmt.Println(s2)

	fmt.Println()

	// comparing two strings
	s3 := "Apple"
	s4 := "apple"
	
	if s3 == s4 {
        fmt.Println("the strings are equal")
    } else {
        fmt.Println("the strings are not equal")
    }

	
    if strings.EqualFold(s3, s4) {
        fmt.Println("the strings are equal")
    } else {
        fmt.Println("the strings are not equal")
	}
	
	fmt.Println()

	// escape sequence
	s5 := "House\tman\nwoman\ta dog\n"
    fmt.Println(s5)

    s6 := "Have a \"safe flight\""
	fmt.Println(s6)
	
	fmt.Println()

	// looping strings - using a for loop, it loops the string over bytes
	s7 := "Green"

    for idx, s := range s7 {
    	fmt.Printf("The index number of %c is %d\n", s, idx)
    }
	fmt.Println()

    fmt.Println("using Bytes:")

    for i := 0; i < len(s7); i++ {
        fmt.Printf("%x ", s7[i])
    }

    fmt.Println()

	

}