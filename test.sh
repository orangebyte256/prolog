for test in `ls test/in`
do
  ./prolog < "test/in/"$test > tmp
  if diff tmp "test/out/"$test > /dev/null; then 
	  echo $test success;
	else
		echo $test failed;
  fi
done
