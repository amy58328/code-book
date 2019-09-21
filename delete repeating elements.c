// l 陣列長度
// 陣列要先sort 過
// ll 削減過後的長度

int del_re(int l )
{
	int ll = l ;
	int index = 0 ; 
	int i = 1 ;
	for(;i<l;i++)
	{
		if(special[i] != special[index])
		{
			index++;
			special[index] = special[i] ;
		}

		else 
		{
			ll--;
		}
	}	
	return ll ;
}