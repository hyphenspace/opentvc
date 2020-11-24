#!/bin/bash 

UNITY_TEST_API="https://github.com/ThrowTheSwitch/Unity"

if [ -d "unity" ]
then
	echo "Unity Test API folder already"
	echo "Check the folder named unity!"

else
	git clone ${UNITY_TEST_API}
	mv Unity/src unity/ && rm -rf Unity
	echo "Unity Test API has been acquired"
fi
