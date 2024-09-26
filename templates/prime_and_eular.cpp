bool isnp[N];
int phi[N];
vector<int> primes;

void get_primes()
{
    phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.emplace_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes)
        {
            if (p * i >= N)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}