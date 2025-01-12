// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2020-2023 The Monero Project

#ifndef FEATHER_ACCOUNTSWITCHERDIALOG_H
#define FEATHER_ACCOUNTSWITCHERDIALOG_H

#include <QDialog>

#include "appcontext.h"
#include "components.h"
#include "model/SubaddressAccountModel.h"

namespace Ui {
    class AccountSwitcherDialog;
}

class AccountSwitcherDialog : public WindowModalDialog
{
    Q_OBJECT

public:
    explicit AccountSwitcherDialog(QSharedPointer<AppContext> ctx, QWidget *parent = nullptr);
    ~AccountSwitcherDialog() override;

private slots:
    void showContextMenu(const QPoint& point);
    void updateSelection();

private:
    void switchAccount();
    void copyLabel();
    void copyBalance();
    void editLabel();

    Monero::SubaddressAccountRow* currentEntry();

    QScopedPointer<Ui::AccountSwitcherDialog> ui;
    QSharedPointer<AppContext> m_ctx;
    SubaddressAccountModel *m_model;
    SubaddressAccountProxyModel *m_proxyModel;
};

#endif //FEATHER_ACCOUNTSWITCHERDIALOG_H
