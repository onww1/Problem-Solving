package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	open()

	close()
}

var (
	sc           *bufio.Scanner
	wr           *bufio.Writer
	inputStream  *os.File
	outputStream *os.File
)

func scanInt() int {
	sc.Scan()
	ret, _ := strconv.Atoi(sc.Text())
	return ret
}

func open() {
	sc = bufio.NewScanner(inputStream)
	sc.Split(bufio.ScanWords)

	wr = bufio.NewWriter(outputStream)
}

func close() {
	wr.Flush()
	inputStream.Close()
	outputStream.Close()
}

// func init() {
// 	inputStream = os.Stdin
// 	outputStream = os.Stdout
// }

func init() {
	inputStream, _ = os.Open("input.txt")
	outputStream, _ = os.Create("output.txt")
}
