#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<vector<bool> > >	get_shapes();
int	get_masked_sum(size_t x, size_t y, const vector<vector<int> >& vec, const vector<vector<bool> >& shape);
int	get_max_of_shape(const vector<vector<int> >& vec, const vector<vector<bool> >& shape);

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	int	m; cin >> m;
	vector<vector<int> >	vec(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> vec[i][j];
		}	
	}
	vector<vector<vector<bool> > >	shapes = get_shapes();
	int	max_num = 0;
	for (size_t i = 0; i < shapes.size(); ++i) {
		max_num = max(max_num, get_max_of_shape(vec, shapes[i]));
	}
	cout << max_num << endl;
}

int	get_masked_sum(size_t x, size_t y, const vector<vector<int> >& vec, const vector<vector<bool> >& shape)
{
	int	sum = 0;
	for (size_t i = 0; i < shape.size(); ++i, ++y) {
		for (size_t j = 0, xx = x; j < shape[0].size(); ++j, ++xx) {
			if (shape[i][j]) {
				sum += vec[y][xx];
			}
		}	
	}
	return (sum);
}

int	get_max_of_shape(const vector<vector<int> >& vec, const vector<vector<bool> >& shape)
{
	int	out = 0;
	for (size_t i = 0, end = vec.size() - shape.size(); i <= end; ++i) {
		for (size_t j = 0, end = vec[0].size() - shape[0].size(); j <= end; ++j) {
			out = max(out, get_masked_sum(j, i, vec, shape));
		}	
	}
	return (out);
}

vector<vector<vector<bool> > >	get_shapes()
{
	vector<vector<vector<bool> > >	shapes;
	vector<vector<bool> >	square(2, vector<bool>(2, true));
	shapes.push_back(square);
	vector<vector<bool> >	line1(1, vector<bool>(4, true));
	shapes.push_back(line1);
	vector<vector<bool> >	line2(4, vector<bool>(1, true));
	shapes.push_back(line2);
	vector<vector<bool> >	l1(3, vector<bool>(2, true));
	l1[0][1] = false; l1[1][1] = false;
	shapes.push_back(l1);
	vector<vector<bool> >	l2(3, vector<bool>(2, true));
	l2[0][0] = false; l2[1][0] = false;
	shapes.push_back(l2);
	vector<vector<bool> >	l3(3, vector<bool>(2, true));
	l3[1][1] = false; l3[2][1] = false;
	shapes.push_back(l3);
	vector<vector<bool> >	l4(3, vector<bool>(2, true));
	l4[1][0] = false; l4[2][0] = false;
	shapes.push_back(l4);
	vector<vector<bool> >	l5(2, vector<bool>(3, true));
	l5[0][1] = false; l5[0][2] = false;
	shapes.push_back(l5);
	vector<vector<bool> >	l6(2, vector<bool>(3, true));
	l6[1][1] = false; l6[1][2] = false;
	shapes.push_back(l6);
	vector<vector<bool> >	l7(2, vector<bool>(3, true));
	l7[0][0] = false; l7[0][1] = false;
	shapes.push_back(l7);
	vector<vector<bool> >	l8(2, vector<bool>(3, true));
	l8[1][0] = false; l8[1][1] = false;
	shapes.push_back(l8);
	vector<vector<bool> >	s1(3, vector<bool>(2, true));
	s1[0][1] = false; s1[2][0] = false;
	shapes.push_back(s1);
	vector<vector<bool> >	s2(3, vector<bool>(2, true));
	s2[0][0] = false; s2[2][1] = false;
	shapes.push_back(s2);
	vector<vector<bool> >	s3(2, vector<bool>(3, true));
	s3[0][0] = false; s3[1][2] = false;
	shapes.push_back(s3);
	vector<vector<bool> >	s4(2, vector<bool>(3, true));
	s4[1][0] = false; s4[0][2] = false;
	shapes.push_back(s4);
	vector<vector<bool> >	t1(2, vector<bool>(3, true));
	t1[1][0] = false; t1[1][2] = false;
	shapes.push_back(t1);
	vector<vector<bool> >	t2(3, vector<bool>(2, true));
	t2[0][0] = false; t2[2][0] = false;
	shapes.push_back(t2);
	vector<vector<bool> >	t3(2, vector<bool>(3, true));
	t3[0][0] = false; t3[0][2] = false;
	shapes.push_back(t3);
	vector<vector<bool> >	t4(3, vector<bool>(2, true));
	t4[0][1] = false; t4[2][1] = false;
	shapes.push_back(t4);
	return (shapes);
}