# ----------------------------
# Makefile Options
# ----------------------------

NAME = MINISH
ICON = icon.png
DESCRIPTION = "test v1"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
