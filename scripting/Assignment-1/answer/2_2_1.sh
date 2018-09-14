sed -n '/Anycity/p' address-book.csv | sed --expression 's/,.*/ /'
