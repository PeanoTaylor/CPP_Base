#ifndef __LINE_HPP__
#define __LINE_HPP__

class Line {
public:
    Line(int x1, int y1, int x2 ,int y2);
    ~Line();
    void printLine();              // 打印两个点的坐标

private:
    class LineImpl;               // 前向声明，实现细节对外隐藏
    LineImpl* m_pimpl;            // 实现类指针
};


#endif

