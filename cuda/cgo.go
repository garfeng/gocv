//go:build !customenv && !static
// +build !customenv,!static

package cuda

// Changes here should be mirrored in gocv/cgo.go and contrib/cgo.go.

/*
#cgo !windows LDFLAGS: -L/usr/local/lib
#cgo CXXFLAGS:   --std=c++11
#cgo windows  LDFLAGS:   -LC:/opencv/cvglue/bin
#cgo LDFLAGS: -lgocv_cuda
*/
import "C"
