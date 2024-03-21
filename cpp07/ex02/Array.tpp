template <typename T>
Array<T>::Array() : _array(NULL), _length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n) {
	_array = new T[_length];
}

template <typename T>
Array<T>::Array(const Array &Copy) : _length(Copy._length) {
	_array = new T[_length];
	std::memcpy(_array, Copy._array, sizeof(T) * _length);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &Copy) {
	if (this != Copy) {
		delete[] _array;
		_length = Copy._length;
		_array = new T[Copy._length];
		std::memcpy(_array, Copy._array, _length * sizeof(T));
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
T &Array<T>::operator[](int idx) {
	if (idx < 0 || idx >= _length)
		throw std::out_of_range("Index is out of range");
	return _array[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _length;
}
