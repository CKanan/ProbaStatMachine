SOURCES=$(wildcard *.c)

main: $(SOURCES)
	gcc $^ -o $@

# clean: 
# 	rm $(SOURCES) 