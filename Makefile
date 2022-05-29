#############################################################################
# @file		: Makefile
# @brief 	: Top Makefile 
# Authot	: Ming
# @E-Mail	: Ming <1546274931@qq.com>
# This is top top Makefile of this list program
#############################################################################

.PHONY : single double

single:
	$(MAKE) -C ./SingleList main
double:
	$(MAKE) -C ./DoubleList main
clean:
	$(MAKE) -C ./SingleList clean
	$(MAKE) -C ./DoubleList clean
	
