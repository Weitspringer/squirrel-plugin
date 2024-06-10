# Makefile for squirrel scheduler plugin

AUTOMAKE_OPTIONS = foreign

AM_CXXFLAGS = -fexceptions

PLUGIN_FLAGS = -module -avoid-version --export-dynamic

AM_CPPFLAGS = -DSLURM_PLUGIN_DEBUG -I$(top_srcdir) -I$(top_srcdir)/src/common -I$(top_srcdir)/src/interfaces

pkglib_LTLIBRARIES = sched_squirrel.la

sched_squirrel_la_SOURCES = \
			squirrel_wrapper.c \
			squirrel.c	\
			squirrel.h
sched_squirrel_la_LDFLAGS = $(PLUGIN_FLAGS)