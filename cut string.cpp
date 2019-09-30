void cut_string()
{
	vector<string>arr;
		
	istringstream delim(str);

	string temp;

	while(getline(delim,temp,' '))
	{
		for(int i=0 ; i<temp.size() ;i++)
		{
			if(temp[i] >=65 && temp[i]<=90)
			{
				temp[i] += 32;
			}
		}

		arr.push_back(temp);
	}
}
