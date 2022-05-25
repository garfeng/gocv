package gocv

import (
	"fmt"
	"path/filepath"
	"reflect"
	"runtime"
)

func Caller(skip int) (name string, line int) {
	var file string
	_, file, line, ok := runtime.Caller(skip + 1)
	if !ok {
		return "", 0
	}

	root, name := filepath.Split(file)

	base := filepath.Base(root)

	return base + "/" + name, line
}

func PanicWithCaller(skip int, e any) {
	file, line := Caller(skip + 1)

	msg := fmt.Sprint("[", file, ":", line, "] ", e)
	panic(msg)
}

func MustEqual(a any, b any, format string, i ...interface{}) {
	if reflect.DeepEqual(a, b) {
		return
	}

	if format == "" {
		PanicWithCaller(1, fmt.Sprintf("%v != %v", a, b))
	} else {
		s1 := fmt.Sprintf(format, i...)
		//	s2 := fmt.Sprintf("(%v != %v)", a, b)
		PanicWithCaller(1, s1)
	}
}

func Must(a bool, format string, i ...interface{}) {
	if a {
		return
	}
	PanicWithCaller(1, fmt.Sprintf("("+format+") != true", i...))
}

func MustNot(a bool, format string, i ...interface{}) {
	if !a {
		return
	}
	PanicWithCaller(1, fmt.Sprintf(format+" != false", i...))
}

var (
	matTypeSizeMap = map[MatType]int{
		MatTypeCV8U:  1,
		MatTypeCV8S:  1,
		MatTypeCV16U: 2,
		MatTypeCV16S: 2,
		MatTypeCV32S: 4,
		MatTypeCV32F: 4,
		MatTypeCV64F: 8,
	}
)

func sizeOfMatType(mt MatType) int {
	sz := matTypeSizeMap[mt]
	channelNum := (int(mt) >> 3) + 1
	return sz * channelNum
}
