#!/bin/bash


file=$1

if [ ! -f "$file" ]
then
    echo "The file doesn't exist."
    exit 1
fi

# replace 1.0 with 1.1
sed -i 's/HTTP\/1.0/HTTP\/1.1/' $file

# delete comment lines
sed -i '/^#/d' $file

# hyphen - seperated credit cards
sed -i 's/[0-9]\{4\}-[0-9]\{4\}-[0-9]\{4\}-[0-9]\{4\}/XXXX-XXXX-XXXX-XXXX/' "$file"

# continous credit cards
sed -i 's/[0-9]\{16\}/XXXX-XXXX-XXXX-XXXX/' "$file"

# display the output
cat $file


