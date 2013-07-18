# Copyright JerryZhou@outlook.com, Inc. and other Node contributors. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the 
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is 
# furnished to do so, subject to the following condition:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IF PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRCT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#

# src
SRCDIR ?= $(CURDIR)

# platform
PLATFORM ?= $(shell sh -c 'uname -s | tr "[A-Z]" "[a-z]"')

TARGET=abc
INC = -I. -I$(SRCDIR)/include -I$(SRCDIR)/src
VPATH = .:test:src

SRC_PATH=$(foreach dir,$(subst :, ,$(VPATH)),$(wildcard $(dir)/*.cpp))
OBJS := $(subst .cpp,.o,$(SRC_PATH))
$(info OBJS = $(OBJS))

CXX = g++
CXXFLAGS = -g

$(TARGET):$(OBJS) 
	$(CXX) -o $@ $(OBJS) $(INC) $(CXXFLAGS)

$(OBJS):%.o:%.cpp %.cpp.d
	$(CXX) -o $@ -c $< $(INC) $(CXXFLAGS)

DEPS = $(OBJS:.o=.cpp.d)
$(DEPS):%.cpp.d : %.cpp
	$(CXX) $< -MM $(INC) > $<.d

clean:
	@rm -rf $(OBJS) 
	@rm -rf $(DEPS)
	@rm -rf $(TARGET)