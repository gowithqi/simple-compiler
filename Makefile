# Build Configuration
CXX         := clang++
SRCDIR      := src
BUILDDIR    := build
CXXFLAGS    := -g -Wall
TARGET      := sc

# Get File information
SRCEXT      := cpp
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
DEPENDS     := $(OBJECTS:.o=.deps)

all: check

$(TARGET): $(OBJECTS)
	@echo " Linking $@..."
	@$(CXX) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " CC $<"
	@$(CXX) $(CXXFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<

check: $(TARGET)
	@./$(TARGET)

clean:
	@echo " Cleaning...";
	@$(RM) -r $(BUILDDIR) $(TARGET)

-include $(DEPENDS)
  
.PHONY: clean

