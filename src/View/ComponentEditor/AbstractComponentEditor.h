#ifndef VIEW_COMPONENT_EDITOR_ABSTRACT_COMPONENT_EDITOR_H
#define VIEW_COMPONENT_EDITOR_ABSTRACT_COMPONENT_EDITOR_H

#include <QWidget>
#include <QString>

#include "../../Component/AbstractComponent.h"

namespace View
{
    namespace ComponentEditor
    {

        class AbstractComponentEditor : public QWidget
        {
            Q_OBJECT
        public:
            AbstractComponentEditor(QWidget *parent = 0);
            virtual ~AbstractComponentEditor();
            virtual Component::AbstractComponent *create(
                const unsigned int identifier,
                const QString &name,
                const double price,
                const QString &brand,
                const QString &image_path) const = 0;
        };

    }
}

#endif