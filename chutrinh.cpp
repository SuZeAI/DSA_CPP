bool check(int v=1, int u=0)
{
    visited[v] = 1;
    for(auto i : k[v])
    {
        if(!visited[i]) 
        {
            if(check(i, v)) return true;
        }
        else if(i != u)
        {
            return true;
        }
    }
    return false;
}
