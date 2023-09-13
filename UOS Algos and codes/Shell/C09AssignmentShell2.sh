#!\bin\bash
for fileItem in *
do
	if [ -d fileItem ]
	then 
		echo "$fileItem"
	fi
done 

