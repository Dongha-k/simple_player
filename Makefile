CC = gcc

CFLAGS += -Wall -g \
          -Iinc \
          -Iffmpeg/include

LDFLAGS += \
          -Lffmpeg/lib

LIBS += \
          -lavformat \
          -lavcodec \
          -lavutil \
          -lswscale \
          -lswresample \
          -lz \
          -lbz2

TARGET = simple_player

all:
	$(CC) src/*.c $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)