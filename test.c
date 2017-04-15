#include <stdio.h>
#include <stdlib.h>


typedef struct	s_test
{
  int i;
}		t_test;

void	ft_test(t_test *test)
{
  test->i++;
}

int main(void)
{
  t_test test;

  test.i = 0;
  ft_test(&test);
  printf("%d", test.i);
  return (0);
}
