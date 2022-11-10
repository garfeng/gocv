//go:build !customenv && !static
// +build !customenv,!static

package gocv

// Changes here should be mirrored in contrib/cgo.go and cuda/cgo.go.

/*
#cgo !windows LDFLAGS: -L./cvglue/build
#cgo CXXFLAGS:   --std=c++11
#cgo windows  LDFLAGS:   -LC:/opencv/cvglue/
#cgo LDFLAGS: -lgocv
*/
import "C"
