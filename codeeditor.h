#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QColor>

class CodeEditor;

class LineNumberArea : public QWidget
{
    Q_OBJECT
public:
    explicit LineNumberArea(CodeEditor* editor);
    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    CodeEditor* m_editor;
};

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit CodeEditor(QWidget* parent = nullptr);
    void lineNumberAreaPaintEvent(QPaintEvent* event);
    int lineNumberAreaWidth() const;
    void setLineNumbersVisible(bool visible);
    bool lineNumbersVisible() const;
    int currentLine() const;
    int currentColumn() const;
    void setLineNumberColors(const QColor& bg, const QColor& fg);
protected:
    void resizeEvent(QResizeEvent* event) override;
private slots:
    void updateLineNumberAreaWidth(int);
    void updateLineNumberArea(const QRect& rect, int dy);
    void highlightCurrentLine();
private:
    QWidget* m_lineNumberArea;
    bool m_showLineNumbers;
    QColor m_lnBgColor;
    QColor m_lnTextColor;
};

#endif // CODEEDITOR_H