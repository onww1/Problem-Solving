data sum( vector<data> &tree, int i )
{
	data answer = 0;
	while ( i > 0 )
	{
		answer += tree[i];
		i -= ( i & -i ); // 최하위 비트 지우기
	}

	return answer;
}


void update( vector<data> &tree, int i, data difference )
{
	while ( i < tree.size() )
	{
		tree[i] += difference;
		i += ( i & -i );
	}
}


for ( int i = 1; i <= n; i++ )
{
	update( tree, i, arr[i] );
}

