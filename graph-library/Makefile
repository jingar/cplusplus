INCLUDES = -I library/
LIB = library/libbookgui.a
FLTK_LIBS = -L/usr/local/lib/ -lfltk_images -lfltk_png -lfltk_jpeg -lfltk -lXext -lpthread -ldl -lm -lX11
all:
	g++ $(INCLUDES) -o $(TARGET) $(SOURCE) $(LIB) $(FLTK_LIBS)
