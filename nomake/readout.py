from ctypes import cdll, c_char_p, c_int, POINTER, c_longlong
import sys

lib = cdll.LoadLibrary('./libjppp.so')


class JDAQEventReader(object):
    lib.JDAQEventReader_new.argtypes = [c_char_p]
    lib.JDAQEventReader_get_tots.restype = POINTER(c_int)

    def __init__(self, filename):
        print("Filename: {0}".format(filename))
        self.obj = lib.JDAQEventReader_new(filename)

    def get_frame_index(self):
        return lib.JDAQEventReader_get_frame_index(self.obj)

    def retrieve_next_event(self):
        lib.JDAQEventReader_retrieve_next_event(self.obj)

    def get_tots(self):
        return lib.JDAQEventReader_get_tots(self.obj)

    @property
    def has_next(self):
        return lib.JDAQEventReader_has_next(self.obj)

    def __iter__(self):
        while self.has_next:
            self.retrieve_next_event()
            yield (self.get_frame_index(), self.get_tots())


for idx, event in enumerate(JDAQEventReader(sys.argv[1])):
    frame_index, hits_array = event
    print(42*'=')
    print("Event {0}, FrameIndex {1}:".format(idx, frame_index))
    print("--- Hits:")
    for i in range(5):
        print(int(hits_array[i]))

