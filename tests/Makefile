SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)
	$(MAKE) -C $^

clean: $(SUBDIRS)
	$(MAKE) clean -C $^

.PHONY: all $(SUBDIRS)