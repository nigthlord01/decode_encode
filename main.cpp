#include <stdio.h>
#include <iostream>
#include <string>
#define __STDC_CONSTANT_MACROS
#ifdef __cplusplus
extern "C" {
    
    
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libavutil/log.h>
#include <libavutil/dict.h>


#ifdef __cplusplus
};
#endif

int main()
{
double fps=0;
std::string path;
av_register_all();
avformat_network_init();
std::cout<<"Введите путь до фаила"<<std::endl;
std::cin>>path;
const char* buf = path.data();
AVFormatContext *formatCtx = avformat_alloc_context();
if(avformat_open_input(&formatCtx,buf, nullptr, nullptr) !=0)
{
	std::cout<<buf<<std::endl;
	std::cout<<"Фаил не открыт.."<<std::endl;
return -1;
}
	avformat_find_stream_info(formatCtx, NULL);
	int count_streams = formatCtx->nb_streams;
	std::cout<<"количество потоков: "<<count_streams<<std::endl;



for (int i=0; i<formatCtx->nb_streams; i++)
{
	AVCodecParameters *codec_params = formatCtx->streams[i]->codecpar;
	if(codec_params->codec_type == AVMEDIA_TYPE_AUDIO)
	{
	std::cout<<"AUDIO codec: " << avcodec_get_name(codec_params->codec_id)<<std::endl;
	}
	else 
		if (codec_params->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			std::cout<<"VIDEO codec: " << avcodec_get_name(codec_params->codec_id)<<std::endl;
			double dur_min = formatCtx->streams[i]->duration/1000/60;
			std::cout<<"Длительность общая: "<<dur_min<<" s"<<std::endl;
		}
	//std::cout<<"количество кадров: "<< formatCtx->streams[i]->nb_frames<<std::endl;
	//std::cout<<"Длительность : "<<formatCtx->streams[i]->duration/1000<<"ms"<<std::endl;
	fps = av_q2d(formatCtx->streams[i]->r_frame_rate);
	
}
std::cout<<"FPS : " <<fps<<std::endl;
//AVDictionaryEntry *tag = nullptr;
//while ((tag=av_dict_get(formatCtx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) 
//{
//std::cout<<tag->key<< ": "<<tag->value<<std::endl;
//}
avformat_close_input(&formatCtx);
avformat_free_context(formatCtx);

return 0;
}
