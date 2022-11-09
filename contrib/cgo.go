//go:build !customenv && !static
// +build !customenv,!static

package contrib

// Changes here should be mirrored in gocv/cgo.go and cuda/cgo.go

/*
#cgo !windows LDFLAGS: -L./../cvglue/build
#cgo CXXFLAGS:   --std=c++11
#cgo CPPFLAGS:   -I./../cvglue
#cgo windows  LDFLAGS:   -L./../cvglue/build/Release/
#cgo LDFLAGS: -lcvglue
*/
import "C"
