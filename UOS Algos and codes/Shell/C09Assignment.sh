#\bin\bash
echo "Number of terms in Fibbonacci Series"
read n
a=0
b=1
for((i=0;i<5;i++))
do
	c=$((a+b))
	a=$b;
	b=$c;
	echo "$c "
done


