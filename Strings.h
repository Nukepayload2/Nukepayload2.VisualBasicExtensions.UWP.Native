#pragma once
#include "VbStrConv.h"
#include <Windows.h>
using namespace Platform;
namespace Nukepayload2
{
	namespace VisualBasicExtensions
	{
		namespace UWP
		{
			namespace Native
			{
				public ref class Strings sealed
				{
				public:
					static int VbStrConvToMapFlags(VbStrConv value)
					{
						int flag = 0;
						//宽窄
						if ((value & VbStrConv::Wide) == VbStrConv::Wide)
						{
							flag |= LCMAP_FULLWIDTH;
						}
						else if ((value & VbStrConv::Narrow) == VbStrConv::Narrow)
						{
							flag |= LCMAP_HALFWIDTH;
						}
						//大小写
						if ((value & VbStrConv::ProperCase) == VbStrConv::ProperCase)
						{
							flag |= LCMAP_TITLECASE;
						}
						else if ((value & VbStrConv::Uppercase) == VbStrConv::Uppercase)
						{
							flag |= LCMAP_UPPERCASE;
						}
						else if ((value & VbStrConv::Lowercase) == VbStrConv::Lowercase)
						{
							flag |= LCMAP_LOWERCASE;
						}
						else if ((value & VbStrConv::LinguisticCasing) == VbStrConv::LinguisticCasing)
						{
							flag |= LCMAP_LINGUISTIC_CASING;
						}
						//日语
						if ((value & VbStrConv::Hiragana) == VbStrConv::Hiragana)
						{
							flag |= LCMAP_HIRAGANA;
						}
						else if ((value  & VbStrConv::Katakana) == VbStrConv::Katakana)
						{
							flag |= LCMAP_KATAKANA;
						}
						//汉语
						if ((value & VbStrConv::SimplifiedChinese) == VbStrConv::SimplifiedChinese)
						{
							flag |= LCMAP_SIMPLIFIED_CHINESE;
						}
						else if ((value & VbStrConv::TraditionalChinese) == VbStrConv::TraditionalChinese)
						{
							flag |= LCMAP_TRADITIONAL_CHINESE;
						}
						return flag;
					}
					static String^ LCMapString(String^ LocaleName, int MapFlags, String^ Source)
					{
						int len = Source->Length();
						auto str = ref new String(new wchar_t[len + 1], len);
						LCMapStringEx(LocaleName->Begin(), MapFlags, Source->Begin(), len, const_cast<wchar_t*>(str->Begin()), len, NULL, NULL, NULL);
						return str;
					}
					static String^ LCMapString(int MapFlags, String^ Source)
					{
						int len = Source->Length();
						auto str = ref new String(new wchar_t[len + 1], len);
						LCMapStringEx(LOCALE_NAME_USER_DEFAULT, MapFlags, Source->Begin(), len, const_cast<wchar_t*>(str->Begin()), len, NULL, NULL, NULL);
						return str;
					}
				};
			}
		}
	}
}
