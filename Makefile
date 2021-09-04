
ragel-go-example/atof/atof.go: ragel-go-example/atof/atof.rl
	ragel -Z -G2 $^ -o $@
