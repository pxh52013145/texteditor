#include "codeeditor.h"
#include <QPainter>
#include <QTextBlock>

LineNumberArea::LineNumberArea(CodeEditor* editor) : QWidget(editor), m_editor(editor) {}

QSize LineNumberArea::sizeHint() const { return QSize(m_editor->lineNumberAreaWidth(), 0); }

void LineNumberArea::paintEvent(QPaintEvent* event) { m_editor->lineNumberAreaPaintEvent(event); }

CodeEditor::CodeEditor(QWidget* parent) : QPlainTextEdit(parent), m_lineNumberArea(new LineNumberArea(this)), m_showLineNumbers(true)
{
    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

void CodeEditor::setLineNumbersVisible(bool visible)
{
    m_showLineNumbers = visible;
    updateLineNumberAreaWidth(0);
    m_lineNumberArea->update();
}

bool CodeEditor::lineNumbersVisible() const { return m_showLineNumbers; }

int CodeEditor::lineNumberAreaWidth() const
{
    if (!m_showLineNumbers) return 0;
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) { max /= 10; ++digits; }
    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
    return space;
}

void CodeEditor::updateLineNumberAreaWidth(int)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect& rect, int dy)
{
    if (dy) m_lineNumberArea->scroll(0, dy);
    else m_lineNumberArea->update(0, rect.y(), m_lineNumberArea->width(), rect.height());
    if (rect.contains(viewport()->rect())) updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent* event)
{
    QPlainTextEdit::resizeEvent(event);
    QRect cr = contentsRect();
    m_lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;
    QColor lineColor = palette().alternateBase().color();
    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
    setExtraSelections(extraSelections);
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent* event)
{
    if (!m_showLineNumbers) return;
    QPainter painter(m_lineNumberArea);
    painter.fillRect(event->rect(), palette().base());
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(palette().text().color());
            painter.drawText(0, top, m_lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

int CodeEditor::currentLine() const { return textCursor().blockNumber() + 1; }

int CodeEditor::currentColumn() const { return textCursor().positionInBlock() + 1; }