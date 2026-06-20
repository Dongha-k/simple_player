#include <stdio.h>
#include <libavformat/avformat.h>

AVFormatContext* fmtCtx;

int main(void) {
    char errbuf[256];    
    int ret = avformat_open_input(&fmtCtx, "stream/input_1920_1080_h264.mp4", NULL, NULL);
    if (ret != 0) {
        av_strerror(ret, errbuf, sizeof(errbuf));
        printf("open failed : %s\n", errbuf);
        return -1;
    }
    avformat_find_stream_info(fmtCtx, NULL);
    printf("========= Stream Information =========\n");
    printf("[1] stream number = %d\n", fmtCtx->nb_streams);
    printf("[2] time = %lld(sec)\n", fmtCtx->duration / AV_TIME_BASE);
    printf("[3] bitrate = %lld\n", fmtCtx->bit_rate);

    avformat_close_input(&fmtCtx);

    return 0;
}
