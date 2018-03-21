#include "Main.h"

namespace Host
{
	
	bool refillCallback(VstPlugin& vstPlugin, float* const data, uint32_t availableFrameCount, const WAVEFORMATEX* const mixFormat) {
		vstPlugin.processEvents();

		const auto nDstChannels = mixFormat->nChannels;
		const auto nSrcChannels = vstPlugin.getChannelCount();
		const auto vstSamplesPerBlock = vstPlugin.getBlockSize();

		int ofs = 0;
		while (availableFrameCount > 0) {
			size_t outputFrameCount = 0;
			float** vstOutput = vstPlugin.processAudio(availableFrameCount, outputFrameCount);

			// VST vstOutput[][] format :
			//  vstOutput[a][b]
			//      channel = a % vstPlugin.getChannelCount()
			//      frame   = b + floor(a/2) * vstPlugin.getBlockSize()

			// wasapi data[] format :
			//  data[x]
			//      channel = x % mixFormat->nChannels
			//      frame   = floor(x / mixFormat->nChannels);

			const auto nFrame = outputFrameCount;
			for (size_t iFrame = 0; iFrame < nFrame; ++iFrame) {
				for (size_t iChannel = 0; iChannel < nDstChannels; ++iChannel) {
					const int sChannel = iChannel % nSrcChannels;
					const int vstOutputPage = (iFrame / vstSamplesPerBlock) * sChannel + sChannel;
					const int vstOutputIndex = (iFrame % vstSamplesPerBlock);
					const int wasapiWriteIndex = iFrame * nDstChannels + iChannel;
					*(data + ofs + wasapiWriteIndex) = vstOutput[vstOutputPage][vstOutputIndex];
				}
			}

			availableFrameCount -= nFrame;
			ofs += nFrame * nDstChannels;
		}
		return true;
	}
}