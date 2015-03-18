class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int i = 0;
		uint32_t result=0x00000000;
		for(i=0;i<32;i++)
		{
			result = result*2|(n&0x00000001);
			n = n/2;
		}
		return result;
	}
};