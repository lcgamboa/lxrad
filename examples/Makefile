SUBDIRS= clock  editor  geditor  getlinks  imageview motor  simple  sin
.PHONY: $(SUBDIRS)


all:$(SUBDIRS)

install:$(SUBDIRS)
	
clean:$(SUBDIRS)
	
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

